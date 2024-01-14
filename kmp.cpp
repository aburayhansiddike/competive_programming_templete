class kmp{
    public:
        vector<int > lps;
        int preIdx = 0, sufIdx = 1;

        void createLps(string &s){
            int n = (int)s.size();
            lps.resize(n, 0ll);
            
            while(sufIdx < n){
                if(s[preIdx] == s[sufIdx]){
                    lps[sufIdx] = preIdx + 1;
                    sufIdx += 1;
                    preIdx += 1;
                }else{
                    if(preIdx == 0){
                        lps[sufIdx] = 0;
                        sufIdx += 1;
                    }else{
                        preIdx = lps[preIdx - 1];
                    }
                }
            }
        }

        vector<int > maching(string& text, string& pattern){
            int textIdx = 0, patternIdx = 0;
            int n = (int) text.size();
            vector<int > indexs;
            while(textIdx < n){
                if(text[textIdx] == pattern[patternIdx]){
                    textIdx += 1;
                    patternIdx += 1;
                }else{
                    if(patternIdx != 0){
                        patternIdx = lps[patternIdx - 1];
                    }else{
                        textIdx += 1;
                    }
                }
                if(patternIdx == (int) pattern.size()){
                    indexs.push_back(textIdx - (int) pattern.size());
                    patternIdx = lps[patternIdx - 1];
                }
            }

            return indexs;
        }
};
