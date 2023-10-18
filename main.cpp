#include<bits/stdc++.h>
#include<fstream>
#include<chrono>
using namespace std;
using namespace std::chrono;

class Node {
	Node *links[26];
	bool flag = false;
	public:
	bool containKey(char ch) {
		return (links[ch - 'a'] != NULL);  //checking whether it contains the reference or not
	}
	void put(char ch, Node *node) {
		links[ch - 'a'] = node;     //Setting up the reference
	}
	Node *get(char ch) {
		return links[ch - 'a'];   //Returning the reference
	}
	void setEnd() {
		flag = true;
	}
	bool isEnd() {
		return flag;  //checking whether the word is completed or not
	}
};
class Trie {
private:
	Node* root;
public:
	Trie() {
		root = new Node();
	}

	void insert(string word) {
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				node->put(word[i], new Node());
			}
			node = node->get(word[i]);
		}
		node->setEnd();
	}
	vector<int> getSuffixIndices(string word){
	    vector<int>indx;
	    Node* curr=root;
	    for(int i=0;i<word.size();i++) {
	        if(!curr->containKey(word[i]))
	        return indx;

	        curr=curr->get(word[i]);
	        if(curr->isEnd())
	        indx.push_back(i+1);
	    }
	    return indx;
	}
};
int main()
{
    auto start= chrono::steady_clock::now();
    vector<string>words;
    ifstream inputFile("Input_02.txt");
     if(!inputFile.is_open()) {
        cout<<"Could not open the file \n";
        return 0;
     }
     string input;
     while(getline(inputFile, input)){
        words.push_back(input);
     }
     inputFile.close();

    Trie trie;
    queue<pair<string,string>>q; //<word,suffix>

    for(int i=0;i<words.size();i++){
        trie.insert(words[i]);
    }
    vector<int>indices;
    for(int i=0;i<words.size();i++){
        indices=trie.getSuffixIndices(words[i]);
        if(indices.size()==0)
        continue;

        for(auto j: indices){
            if(j>=words[i].length())
            break;
            string suff=words[i].substr(j);
            q.push({words[i],suff});
        }
    }

    int maxlen=0;
    string longestWord,secLongestWord;

    while(!q.empty()){
        auto it=q.front();
        q.pop();

        indices=trie.getSuffixIndices(it.second);
        for(int i: indices){
            if(i==it.second.size()){
                if(it.first.size()>maxlen){
                    secLongestWord=longestWord;
                    maxlen=it.first.size();
                    longestWord=it.first;
                }
            }
            else{
                q.push({it.first,it.second.substr(i)});
            }
        }
    }
      auto end= chrono::steady_clock::now();
      auto duration = duration_cast<milliseconds>(end-start);
      cout<<"The longest compounded word is "<<longestWord<<endl;
      cout<<"The second longest compounded word is "<<secLongestWord<<endl;
      cout<<"Time taken to process file "<<chrono::duration_cast<chrono::milliseconds>(end-start).count()<<" milliseconds"<<endl;

    return 0;
}
