// Level 2, 모음사전
#include <string>

#include <vector>

#include <set>

#include <algorithm>



using namespace std;



int solution(string word) {

    set<string> s;

    string alp = "AEIOU";

    for (char a : alp) {

        for (char b : alp) {

            for (char c: alp) {

                for (char d : alp) {

                    for (char e: alp) {

                        string f = "";
                        f+=a;f+=b;f+=c;f+=d;f+=e;

                        for (int i = 1; i <= 5; ++i) {

                            s.insert(f.substr(0,i));

                        }

                    }

                }

            }

        }

    }

    

    int answer = 0;

    for (string i : s) {

        ++answer;

        if (i == word) break;

    }

    return answer;

}