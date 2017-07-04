PHONY: firsttime all show clean compile test

#http://make.mad-scientist.net/papers/advanced-auto-dependency-generation/#combine
DEPFLAGS = -MT $@ -MMD -MP -MF $(OBJ_DIR)/$*.Td
POSTCOMPILE = @mv -f $(OBJ_DIR)/$*.Td $(OBJ_DIR)/$*.d && touch $@
COMPILE = @$(GPP) $(DEPFLAGS) $(CPP_FLAGS) $(addprefix -I, $(INCLUDES)) -c -o $@ $<
CPP_FLAGS:=-std=c++11 -x c++ -Wall -O0 -g3
LD_FLAGS:=

ifeq ($(ARDUINO),1)
    $(info "Arduino build")
else
    $(info "Native build")
    OBJ_DIR:=native/obj
    TARGET:=$(OBJ_DIR)/main.exe
	GPP:=g++
	INCLUDES:= native/arduino-stubs
	CPP_FILES:= $(wildcard native/arduino-stubs/*.cpp)
	CPP_FILES+= $(wildcard test/*.cpp)

	CPP_FLAGS+= -DF_CPU=8000000
	CPP_FLAGS+= -include "Serial.h" -include "cstdlib" -include "cstring" -include "cctype" -include "cstdio"
endif

external/FakeIt:
	@git clone https://github.com/eranpeer/FakeIt.git external/FakeIt
	@cd $@ && git checkout tags/2.0.4 

external/Catch:
	@git clone https://github.com/philsquared/Catch.git external/Catch
	@cd $@ && git checkout tags/v1.9.5

firsttime: external/FakeIt external/Catch

INCLUDES += \
	sck_beta_v0_9 \
	external/Catch/single_include \
	external/FakeIt/single_header/catch

CPP_FILES += $(wildcard sck_beta_v0_9/*.cpp)
CPP_FILES += sck_beta_v0_9/sck_beta_v0_9.ino
OBJ_FILES += $(patsubst %.ino, $(OBJ_DIR)/%.o, $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(CPP_FILES))))

$(OBJ_DIR):
	@mkdir -p $@

compile: $(OBJ_FILES) |$(OBJ_DIR)

$(OBJ_DIR)/main.exe: compile
	@echo "=> Linking $@"
	@$(GPP) $(LD_FLAGS) -o $@ $(OBJ_FILES)

$(OBJ_DIR)/%.o: sck_beta_v0_9/%.cpp $(OBJ_DIR)/%.d |$(OBJ_DIR)
	@echo "=> $<"
	$(COMPILE)
	$(POSTCOMPILE)

$(OBJ_DIR)/%.o: sck_beta_v0_9/%.ino $(OBJ_DIR)/%.d |$(OBJ_DIR)
	@echo "=> $<"
	$(COMPILE)
	$(POSTCOMPILE)

$(OBJ_DIR)/%.o: native/arduino-stubs/%.cpp $(OBJ_DIR)/%.d |$(OBJ_DIR)
	@echo "=> $<"
	$(COMPILE)
	$(POSTCOMPILE)

$(OBJ_DIR)/%.o: test/%.cpp |$(OBJ_DIR)
	@echo "=> $<"
	$(COMPILE)
	$(POSTCOMPILE)

$(OBJ_DIR)/%.d: ;
.PRECIOUS: $(OBJ_DIR)/%.d
include $(wildcard $(patsubst %,$(OBJ_DIR)/%.d, $(basename $(CPP_FILES))))

$(OBJ_DIR)/.cleanMake: Makefile |$(OBJ_DIR)
	@rm -rf $(OBJ_DIR)/*
	touch $@


all: firsttime $(OBJ_DIR)/.cleanMake $(OBJ_DIR)/main.exe

clean: 
	@rm -rf $(OBJ_DIR)

test: all
	@echo
	@echo "*****************************************************"
	@echo "Running unit tests"
	@$(OBJ_DIR)/main.exe

show:
	$(info bb $(wildcard $(patsubst %,$(OBJ_DIR)/%.d, $(basename $(CPP_FILES)))))
	@echo "*** CPP_FLAGS *** "
	@echo $(CPP_FLAGS)
	@echo

	@echo "*** INCLUDES *** "
	@echo $(INCLUDES)
	@echo

	@echo "*** SOURCES *** "
	@echo $(CPP_FILES)
	@echo

	@echo "*** OBJECTS *** "
	@echo $(OBJ_FILES)
	@echo

