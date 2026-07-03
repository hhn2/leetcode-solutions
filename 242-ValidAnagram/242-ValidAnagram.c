// Last updated: 7/2/2026, 11:16:36 PM
bool isAnagram(char* s, char* t) {
    int size = strlen(s);

    if (strlen(t) != size ){
        return false;
    }

    int freqarr[26] = {0};

    for (int i = 0; i < size; ++i){
        freqarr[s [i] - 97]++;
    }

    for (int i = 0; i < size; i++){
        freqarr[t[i]- 97]--;
    }

    for (int i = 0; i<26; i++){
        if (freqarr[i] != 0){
            return false;
        }
    }

    return true;

    
}