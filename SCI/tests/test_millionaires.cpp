#include "Millionaire/millionaire.h"
#include "OT/emp-ot.h"
#include "utils/emp-tool.h"
#include <iostream>
#include <cassert>
#include <thread>

using namespace sci;
using namespace std;

void millionaire_thread(int party, uint8_t* result, uint64_t number);

void test_millionaire_protocol(uint64_t alice_number, uint64_t bob_number) {
  int party1 = 1; // ALICE
  int party2 = 2; // BOB

  uint8_t bob_result = 0;
  uint8_t alice_result = 0;
  std::thread t1(&millionaire_thread, party1, &alice_result, alice_number);
  std::thread t2(&millionaire_thread, party2, &bob_result, bob_number);

  t1.join();
  t2.join();

  printf("Alice Result: %u\n", alice_result);

  printf("Bob Result: %u\n", bob_result);

  bool expected = alice_number > bob_number;
  bool actual = alice_result ^ bob_result;

  if (!(expected ^ actual)) {
    printf("test passed with x = %lu and y = %lu\n", alice_number, bob_number);
  }
  else {
    printf("test failed with x = %lu and y = %lu\n", alice_number, bob_number);
    assert(false);
  }
}

void millionaire_thread(int party, uint8_t* result, uint64_t number) {
  int port = 32050;
  string address = "127.0.0.1";

  sci::IOPack *ioPack = new sci::IOPack(party, port, "127.0.0.1");
  
  sci::OTPack *otPack = new sci::OTPack(ioPack, party);

  // Create Millionaire Protocol objects
  MillionaireProtocol mil_protocol(party, ioPack, otPack);

  // I believe the number of comparisons is how many numbers you want to compare
  int num_comparisons = 1;
  int bit_length = 8;

  // bit_length is the number of bits in each number (to be compared)
  mil_protocol.compare(result, &number, num_comparisons, bit_length);

  delete ioPack;
  delete otPack;
}

void millionaires_test_main() {
  test_millionaire_protocol(64, 80);
  test_millionaire_protocol(100, 32);
  test_millionaire_protocol(0, 1);
  test_millionaire_protocol(250, 255);
}
