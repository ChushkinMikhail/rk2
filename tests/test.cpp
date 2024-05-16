#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "./../builder.cpp"

TEST(LOLGameDeviceTest, BuildMouseTest) {
  jc::LOLGameDevice LOLBuilder;
  LOLBuilder.BuildMouse();
  
  ASSERT_EQ(LOLBuilder.Device().GetMouse(), "Logitech");
}

TEST(LOLGameDeviceTest, BuildKeyboardTest) {
  jc::LOLGameDevice LOLBuilder;
  LOLBuilder.BuildKeyboard();
  
  ASSERT_EQ(LOLBuilder.Device().GetKeyboard(), "Filco");
}

TEST(LOLGameDeviceTest, BuildHeadphoneTest) {
  jc::LOLGameDevice LOLBuilder;
  LOLBuilder.BuildHeadphone();
  
  ASSERT_EQ(LOLBuilder.Device().GetHeadphone(), "Sennheiser");
}
