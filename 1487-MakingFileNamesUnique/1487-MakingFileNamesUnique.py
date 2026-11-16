# Last updated: 11/15/2026, 7:42:55 PM
1class Solution:
2    def getFolderNames(self, names: list[str]) -> list[str]:
3        counts = {}
4        answer = []
5
6        for name in names:
7            if name in counts:
8                counts[name] += 1
9                wanttoput = name+"("+str(counts[name])+")"
10                while wanttoput in counts:
11                    counts[name]+=1
12                    wanttoput = name+"("+str(counts[name])+")"
13                counts[wanttoput] = 0
14                answer.append(wanttoput)
15                
16            else:
17                answer.append(name)
18                counts[name] = 0
19
20        return answer