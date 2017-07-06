#include "catch.hpp"
#include "fakeit.hpp"
#include "SCKBase.h"
#include <string>

TEST_CASE( "SCKBase testers", "[base]" ) {
    SCKBase sck;


    SECTION("checkText parses request data and returns the request parameter") {
      char requestData [32];

      strcpy (requestData, "foo bar");
      REQUIRE (sck.checkText ("foo", requestData));
      REQUIRE_THAT (requestData, Catch::Matchers::Equals("bar"));

      strcpy (requestData, "foo bar");
      REQUIRE (sck.checkText ("bar", requestData));
      REQUIRE_THAT (requestData, Catch::Matchers::Equals(""));

      strcpy (requestData, "foo bar");
      REQUIRE_FALSE (sck.checkText ("foz", requestData));
      REQUIRE_THAT (requestData, Catch::Matchers::Equals("foo bar"));
    }

    SECTION("checkText with program space pattern") {
      char requestData [32];

      strcpy (requestData, "foo bar");
      REQUIRE (sck.checkText ((const __FlashStringHelper*)"foo", requestData));
      REQUIRE_THAT (requestData, Catch::Matchers::Equals("bar"));

      strcpy (requestData, "foo bar");
      REQUIRE_FALSE (sck.checkText ((const __FlashStringHelper*)"foz", requestData));
      REQUIRE_THAT (requestData, Catch::Matchers::Equals("foo bar"));
    }

    SECTION("compareData compares two strings for equality") {
      REQUIRE (sck.compareData ("foo", "foo"));
      REQUIRE (sck.compareData ("", ""));

      REQUIRE_FALSE (sck.compareData ("foob", "foo"));
      REQUIRE_FALSE (sck.compareData ("foo", "foob"));
      REQUIRE_FALSE (sck.compareData ("foo", ""));
    }
}

  // for (int retryCount = 0; retryCount < COMMAND_MODE_ENTER_RETRY_ATTEMPTS; retryCount++) 
  // {
  //   delay(COMMAND_MODE_GUARD_TIME);
  //   serial1_.print(F("$$$"));
  //   delay(COMMAND_MODE_GUARD_TIME);
  //   serial1_.println();
  //   serial1_.println();
  //   if (findInResponse("\r\n<", 1000))
  //   {
  //     return true;
  //   }
  // }
  // return false;
