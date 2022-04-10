class Solution {
private:
  unordered_map<string, int> moves = // moves["x,y"]: min moves starting from (x, y)
  { 
    {"0,0", 0},
    {"0,1", 3},
    {"0,2", 2},
    {"1,1", 2},
    {"1,2", 1},
    {"2,2", 4}
  };
  
public:
  int minKnightMoves(int x, int y) 
  {
    x = abs(x), y = abs(y);
    if (x > y) swap(x, y);
    
    string key = to_string(x) + "," + to_string(y);
    if (moves.count(key)) 
        return moves[key];

    return moves[key] = 1 + min(minKnightMoves(x-2, y-1), minKnightMoves(x-1, y-2));
  }
};