#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "./../builder.cpp"

TEST(GameDeviceTest, LOLBuilderTest) {
  jc::LOLGameDevice builder;
  builder.BuildMouse();
  builder.BuildKeyboard();
  builder.BuildHeadphone();

  jc::DeviceSuite device = builder.Device();

  EXPECT_EQ(device.mouse, "Logitech");
  EXPECT_EQ(device.keyboard, "Filco");
  EXPECT_EQ(device.headphone, "Sennheiser");
}

TEST(GameDeviceTest, DNFBuilderTest) {
  jc::DNFGameDevice builder;
  builder.BuildMouse();
  builder.BuildKeyboard();
  builder.BuildHeadphone();

  jc::DeviceSuite device = builder.Device();

  EXPECT_EQ(device.mouse, "Razer");
  EXPECT_EQ(device.keyboard, "Cherry");
  EXPECT_EQ(device.headphone, "Beyerdynamic");
}

TEST(LifeTest, CreateDeviceTest) {
  jc::Life life;
  jc::LOLGameDevice LOLBuilder;
  jc::DeviceSuite LOLDevice = life.CreateDevice(LOLBuilder);

  EXPECT_EQ(LOLDevice.mouse, "Logitech");
  EXPECT_EQ(LOLDevice.keyboard, "Filco");
  EXPECT_EQ(LOLDevice.headphone, "Sennheiser");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
