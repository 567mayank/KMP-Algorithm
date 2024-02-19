#include<bits/stdc++.h>
using namespace std;
// Function to bulid LPS
vector<int> lps(string s){
	int n=s.length();
	vector<int> lps(n,0);
	int i=0;
	int j=1;
	while(j<n){
		if(s[i]==s[j]){
			i++;
			lps[j]=i;
			j++;
		}
		else{
			if(i==0){
				lps[j]=0;
				j++;
			}
			else{
				i=lps[i-1];
			}
		}
	}
	return lps;
}
// Real search 
vector<int> kmp(string txt,string pat){
	int n=txt.length();
	int m=pat.length();

    // lps construction
	vector<int> lp=lps(pat);
    
	vector<int> ans;
	int i=0;
	int j=0;
	while(i<n){
		cout<<i<<" "<<j<<endl;
		if(txt[i]==pat[j]){
			i++;
			j++;
		}
		else{
			if(j==0){
				i++;
			}
			else{
				j=lp[j-1];
			}
		}
		if(j==m){
			ans.push_back(i-j);
			j=lp[j-1];
            // We can break here if we want just first matching
		}
	}
	return ans;
}
int main(){
	string txt,pat;
	cin>>txt>>pat;
	vector<int> ans=kmp(txt,pat);
	for(auto i:ans){
		cout<<i<<" ";
	}
}
