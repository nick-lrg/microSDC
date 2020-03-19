#include "UUIDGenerator.hpp"

UUID UUIDGenerator::operator()()
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distribution;

  std::array<uint8_t, 16> bytes{};
  for (int i = 0; i < 16; i += 4)
  {
    *reinterpret_cast<uint32_t*>(bytes.data() + i) = distribution(gen);
  }

  // variant must be 10xxxxxx
  bytes[8] &= 0xBFU;
  bytes[8] |= 0x80U;

  // version must be 0100xxxx
  bytes[6] &= 0x4FU;
  bytes[6] |= 0x40U;

  return UUID{bytes};
}
