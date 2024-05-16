#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "./../builder.cpp"

TEST(LOLGameDeviceTest, BuildMouseTest) {
  jc::LOLGameDevice LOLBuilder;
  LOLBuilder.BuildMouse();
  
  ASSERT_EQ(LOLBuilder.Device().SetMouse(), "Logitech");
}

TEST(LOLGameDeviceTest, BuildKeyboardTest) {
  jc::LOLGameDevice LOLBuilder;
  LOLBuilder.BuildKeyboard();
  
  ASSERT_EQ(LOLBuilder.Device().SetKeyboard(), "Filco");
}

TEST(LOLGameDeviceTest, BuildHeadphoneTest) {
  jc::LOLGameDevice LOLBuilder;
  LOLBuilder.BuildHeadphone();
  
  ASSERT_EQ(LOLBuilder.Device().SetHeadphone(), "Sennheiser");
}
