#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "lab7.h"
#include "./include/doctest.h"


TEST_CASE("testing_bigint_product") {
  std::pair<bigint, bigint> t1 = std::make_pair(bigint("123456789123456789"), bigint("987654321987654321"));
  std::pair<bigint, bigint> t2 = std::make_pair(bigint("111111111111111111"), bigint("222222222222222222"));
  std::pair<bigint, bigint> a1 = myproduct(t1, t2);
  CHECK(a1.first == bigint("13717420986282578913717420986282579"));
  CHECK(a1.second == bigint("219478737297256132112482853738104662"));
}

TEST_CASE("testing_bigint_sum") {
  std::pair<bigint, bigint> t1 = std::make_pair(bigint("123456789123456789"), bigint("987654321987654321"));
  std::pair<bigint, bigint> t2 = std::make_pair(bigint("111111111111111111"), bigint("222222222222222222"));
  std::pair<bigint, bigint> a1 = mysum(t1, t2);
  CHECK(a1.first == bigint("234567900234567900"));
  CHECK(a1.second == bigint("1209876544209876543"));

}

TEST_CASE("showing where approach fails with ints") {
  std::pair<int, int> t1 = std::make_pair(123456789, 2);  
  std::pair<int, int> t2 = std::make_pair(987654321, 3);    

  int num1 = t1.first * t2.first; // will overflow here
  int den1 = t1.second * t2.second;

  std::cout << "INT PRODUCT RESULT (likely overflow): " << num1 << "/" << den1 << std::endl;
  CHECK(num1 < 0); // shouldnt be positive since its overflowing

  int a = 1000000000;
  int b = 3;
  int result = a / b; 

  std::pair<bigint, bigint> b1 = std::make_pair(bigint("123456789"), bigint("2"));
  std::pair<bigint, bigint> b2 = std::make_pair(bigint("987654321"), bigint("3"));
  std::pair<bigint, bigint> bresult = myproduct(b1, b2);
  CHECK(bresult.first != bigint("0")); // confirming no overflow

}

TEST_CASE("comparing int differences for product of fractions") {
  // first int fraction product
  auto start = std::chrono::high_resolution_clock::now();
  std::pair<int, int> t1 = std::make_pair(123, 456);
  std::pair<int, int> t2 = std::make_pair(789, 321);
  int num = t1.first * t2.first;
  int den = t1.second * t2.second;
  int ans = num / den;
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "Time taken for int mult: " << duration.count() << " microseconds" << std::endl;
  std::cout << "-------" << std::endl;
  CHECK(ans == (123 * 789) / (456 * 321));

  // second long int fraction product
  start = std::chrono::high_resolution_clock::now();
  std::pair<long int, long int> t3 = std::make_pair(12345678L, 87654321L);
  std::pair<long int, long int> t4 = std::make_pair(11223344L, 44332211L);
  long int lnum = t3.first * t4.first;
  long int lden = t3.second * t4.second;
  long int lans = lnum / lden;
  end = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "Time taken for long int mult: " << duration.count() << " microseconds" << std::endl;
  std::cout << "-------" << std::endl;
  CHECK(lans == (12345678L * 11223344L) / (87654321L * 44332211L));

  // last big int fraction product
  start = std::chrono::high_resolution_clock::now();
  std::pair< bigint, bigint> t5 = std::make_pair(bigint("123456789123456"), bigint("987654321987654"));
  std::pair< bigint, bigint> t6 = std::make_pair(bigint("111111111111111"), bigint("222222222222222"));
  bigint bnum = t5.first * t6.first;
  bigint bden = t5.second * t6.second;
  bigint bans = bnum / bden;
  end = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "Time taken for bigint mult: " << duration.count() << " microseconds" << std::endl;
  std::cout << "-------" << std::endl;
  CHECK(bans == (t5.first * t6.first) / (t5.second * t6.second));
}

TEST_CASE("comparing int differences for sum of fractions") {
  // first int fraction sum
  auto start = std::chrono::high_resolution_clock::now();
  std::pair<int, int> t1 = std::make_pair(123, 456);
  std::pair<int, int> t2 = std::make_pair(789, 321);  
  int num = t1.first * t2.second + t2.first * t1.second;
  int den = t1.second * t2.second;
  int ans = num / den;
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "Time taken for int sum: " << duration.count() << " microseconds" << std::endl;
  std::cout << "-------" << std::endl;
  CHECK(ans == (123 * 321 + 789 * 456) / (456 * 321));

  // second long int fraction sum
  start = std::chrono::high_resolution_clock::now();
  std::pair<long int, long int> t3 = std::make_pair(12345678L, 87654321L);
  std::pair<long int, long int> t4 = std::make_pair(11223344L, 44332211L);
  long int lnum = t3.first * t4.second + t4.first * t3.second;
  long int lden = t3.second * t4.second;
  long int lans = lnum / lden;
  end = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "Time taken for long int sum: " << duration.count() << " microseconds" << std::endl;
  std::cout << "-------" << std::endl;
  CHECK(lans == (t3.first * t4.second + t4.first * t3.second) / (t3.second * t4.second));

  // last big int fraction sum
  start = std::chrono::high_resolution_clock::now();
  std::pair<bigint, bigint> t5 = std::make_pair(bigint("123456789123456"), bigint("987654321987654"));
  std::pair<bigint, bigint> t6 = std::make_pair(bigint("111111111111111"), bigint("222222222222222"));
  bigint bnum = t5.first * t6.second + t6.first * t5.second;
  bigint bden = t5.second * t6.second;
  bigint bans = bnum / bden;
  end = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "Time taken for bigint sum: " << duration.count() << " microseconds" << std::endl;
  std::cout << "-------" << std::endl;
  CHECK(bans == (t5.first * t6.second + t6.first * t5.second) / (t5.second * t6.second));
}
