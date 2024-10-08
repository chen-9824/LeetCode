/*
1436. 旅行终点站
简单
提示
给你一份旅游线路图，该线路图中的旅行线路用数组 paths 表示，其中 paths[i] = [cityAi, cityBi] 表示该线路将会从 cityAi 直接前往 cityBi 。
请你找出这次旅行的终点站，即没有任何可以通往其他城市的线路的城市。
题目数据保证线路图会形成一条不存在循环的线路，因此恰有一个旅行终点站。

*/
class Solution_1436 {
public:
    string destCity(vector<vector<string>>& paths) {
        string res = "";
        
        if(paths.empty())
        return res;
        for(int i = 0; i < paths.size(); ++i){
            int count = 0;
            for(int j = 0; j < paths.size(); ++j){
                if(paths[i][1] == paths[j][0])
                count += 1;
            }
            if(count == 0){
                res = paths[i][1];
                break;
            }
        }
        return res;
    }
};