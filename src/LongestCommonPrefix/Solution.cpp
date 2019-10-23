#include <iostream>
#include <vector>

#include "../Test.h"

using namespace std;
using namespace leetcode;

class TrieNode {
private:
  const static int R = 26;
  int size = 0;
  bool isEnd = false;
  TrieNode **links;

public:
  TrieNode() {
    links = new TrieNode *[R] { nullptr };
  }
  ~TrieNode() {
    for (int i = 0; i < R; i++) {
      if (links[i] != nullptr)
        delete links[i];
    }
    delete[] links;
  }
  bool containsKey(char ch) { return links[ch - 'a'] != nullptr; }
  TrieNode *get(char ch) { return links[ch - 'a']; }
  void put(char ch, TrieNode *node) {
    links[ch - 'a'] = node;
    size++;
  }
  void setEnd() { isEnd = true; }
  bool getEnd() { return isEnd; }
  int getLinks() { return size; }
};

class Trie {
private:
  TrieNode *root;

public:
  Trie() { root = new TrieNode(); }
  ~Trie() { delete root; }
  void insert(string word) {
    TrieNode *node = root;
    for (int i = 0; i < word.length(); i++) {
      char currentChar = word.at(i);
      if (!node->containsKey(currentChar))
        node->put(currentChar, new TrieNode());
      node = node->get(currentChar);
    }
    node->setEnd();
  }
  string searchLongestPrefix(string word) {
    TrieNode *node = root;
    string prefix = "";
    for (int i = 0; i < word.length(); i++) {
      char currentChar = word.at(i);
      if (node->containsKey(currentChar) && (node->getLinks() == 1) &&
          (!node->getEnd())) {
        prefix.push_back(currentChar);
        node = node->get(currentChar);
      } else
        return prefix;
    }
    return prefix;
  }
};

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty())
      return "";
    if (strs.size() == 1)
      return strs[0];
    Trie *trie = new Trie();
    for (int i = 0; i < strs.size(); i++)
      trie->insert(strs[i]);
    string res = trie->searchLongestPrefix(strs[0]);
    delete trie;
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<string> v1({"flower", "flow", "flight"});
  vector<string> v2({"dog", "racecar", "car"});

  test("case 1", s.longestCommonPrefix(v1), string("fl"));
  test("case 2", s.longestCommonPrefix(v2), string(""));

  return 0;
}
