#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol737;

/*
For example, "great acting skills" and "fine drama talent" are similar,
if the similar word pairs are pairs = [["great", "fine"],
["acting","drama"], ["skills","talent"]].
*/

tuple<vector<string>, vector<string>, vector<pair<string, string>>, bool>
testFixture1()
{
  auto ws1 = vector<string>{"great", "acting", "skills"};
  auto ws2 = vector<string>{"fine", "drama", "talent"};
  auto pairs = vector<pair<string, string>>{
      {"great", "good"}, {"fine", "good"}, {"acting", "drama"}, {"skills", "talent"}};
  return make_tuple(ws1, ws2, pairs, true);
}

/*
the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar,
even though there are no specified similar word pairs.
*/

tuple<vector<string>, vector<string>, vector<pair<string, string>>, bool>
testFixture2()
{
  auto ws1 = vector<string>{"great"};
  auto ws2 = vector<string>{"great"};
  auto pairs = vector<pair<string, string>>{};
  return make_tuple(ws1, ws2, pairs, true);
}

/*
Finally, sentences can only be similar if they have the same number of words.
So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].
*/

tuple<vector<string>, vector<string>, vector<pair<string, string>>, bool>
testFixture3()
{
  auto ws1 = vector<string>{"great"};
  auto ws2 = vector<string>{"doubleplus", "good"};
  auto pairs = vector<pair<string, string>>{{"great", "fine"},
                                            {"acting", "drama"},
                                            {"skills", "talent"}};
  return make_tuple(ws1, ws2, pairs, false);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see " << get<3>(f) << endl;
  Solution sol;
  cout << sol.isSimilar(get<0>(f), get<1>(f), get<2>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see " << get<3>(f) << endl;
  Solution sol;
  cout << sol.isSimilar(get<0>(f), get<1>(f), get<2>(f)) << endl;
}

void test3()
{
  auto f = testFixture3();
  cout << "Expect to see " << get<3>(f) << endl;
  Solution sol;
  cout << sol.isSimilar(get<0>(f), get<1>(f), get<2>(f)) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}