/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/common/shield_exceptions.h"

#include "chrome/test/base/chrome_render_view_host_test_harness.h"

namespace {

typedef testing::Test BraveShieldsExceptionsTest;
using brave::IsWhitelistedCookieException;

TEST_F(BraveShieldsExceptionsTest, IsWhitelistedCookieException) {
  // Cookie exceptions for Google auth domains
  EXPECT_TRUE(IsWhitelistedCookieException(
      GURL("https://www.airbnb.com/"),
      GURL("https://accounts.google.com/o/oauth2/iframe"),
      true));
  EXPECT_FALSE(IsWhitelistedCookieException(
      GURL("https://www.mozilla.org/"),
      GURL("https://www.googletagmanager.com/gtm.js"),
      true));
  EXPECT_FALSE(IsWhitelistedCookieException(
      GURL("https://www.airbnb.com/"),
      GURL("https://accounts.google.com/o/oauth2/iframe"),
      false));
}

}  // namespace
