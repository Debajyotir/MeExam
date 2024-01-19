int secondsToRemoveOccurrences(string s) {
        int n = s.size();
        int zero = 0;
        int one = 0;
        n--;
        while(n>=0 && s[n]=='0')
            n--;
        for(int i=0;i<=n;i++){
            if(i>0 && s[i]=='1' && s[i-1]=='1' && zero>0)
                one++;
            if(i>0 && s[i]=='0' && s[i-1]=='0' && one>0)
                one--;
            if(s[i]=='0')
                zero++;
        }
        return zero + one;
    }