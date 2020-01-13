#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;
public:
    char findTheDifference(string s, string t) {
      unordered_map<char, int> map;
        for (char c : s) {
            map[c] += 1;
        }
       
        for (char c : t) {
            auto mapChar = map.find(c);
            if (mapChar == map.end() || (mapChar != map.end() && mapChar->second==0)) {
                return c;
            } else {
                map[c]--;
            }
        }

        return 'z';
    }
