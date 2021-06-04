#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/* Complete the 'minimumMoves' function below. */

void walking(pair<int, int>& position, vector<vector<int>>& initial_array, vector<vector<char>>& color_array, vector<vector<pair<int, int>>>& pair_array, queue<int, deque<pair<int, int>>>& my_queue, vector<string>& grid){
  int startX = position.first, startY = position.second;
  const int Size = grid.size();

  // right
  for(int j = startY; j < Size; ++j){
    if(initial_array[startX][j] == 0){
      if(color_array[startX][j] == 'W'){
        my_queue.push(make_pair(startX, j));
        pair_array[startX][j] = make_pair(startX, startY);
        color_array[startX][j] = 'G';
      }
    } else if(initial_array[startX][j] == 1){
      color_array[startX][j] = 'B';
      break;
    }
  }
  
  // left
  for(int j = startY; j > -1; --j){
    if(initial_array[startX][j] == 0){
      if(color_array[startX][j] == 'W'){
        my_queue.push(make_pair(startX, j));
        pair_array[startX][j] = make_pair(startX, startY);
        color_array[startX][j] = 'G';
      }
    }else if(initial_array[startX][j] == 1){
      color_array[startX][j] = 'B';
      break;
    }
  }
  
  // down
  for(int i = startX; i < Size; ++i){
    if(initial_array[i][startY] == 0){
      if(color_array[i][startY] == 'W'){
        my_queue.push(make_pair(i, startY));
        pair_array[i][startY] = make_pair(startX, startY);
        color_array[i][startY] = 'G';
      }
    }else if(initial_array[i][startY] == 1){
      color_array[i][startY] = 'B';
      break;
    }
  }
  
  // top
  for(int i = startX; i > -1; --i){
    if(initial_array[i][startY] == 0){
      if(color_array[i][startY] == 'W'){
        my_queue.push(make_pair(i, startY));
        pair_array[i][startY] = make_pair(startX, startY);
        color_array[i][startY] = 'G';
      }
    }else if(initial_array[i][startY] == 1){
      color_array[i][startY] = 'B';
      break;
    }
  }
  color_array[startX][startY] = 'R';
}


int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    const int Size = grid.size();
    vector<vector<int>> initial_array(Size);
    queue<int, deque<pair<int, int>>> my_queue = {};
    
    for(int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid.size(); ++j){
        if(grid[i][j] == '.'){
            initial_array[i].push_back(0);
        }else if(grid[i][j] == 'X'){
            initial_array[i].push_back(1);
        }
      }
    }
    
    if(initial_array[startX][startY] == 1 || initial_array[goalX][goalY] == 1){
        return 0;
    }
    
    vector<vector<char>> color_array;
    vector<vector<pair<int, int>>> pair_array;

    color_array.resize(Size);
    for (auto& row : color_array) {
        row.reserve(Size);
    }

    for(int i = 0; i < Size; ++i){
        for(int j = 0; j < Size; ++j){
        color_array[i].push_back('W');
        } 
    }
    
    pair_array.resize(Size);
    for (auto& row : pair_array) {
        row.reserve(Size);
    }

    pair<int, int> defalut_pair(0, 0);
    for(int i = 0; i < Size; ++i){
        for(int j = 0; j < Size; ++j){
        pair_array[i].push_back(defalut_pair);
        } 
    }
    
    pair<int, int> front_element(startX, startY);
    walking(front_element, initial_array, color_array, pair_array, my_queue, grid);

    while(!my_queue.empty()){
        front_element = my_queue.front();
        if(front_element.first == goalX && front_element.second == goalY){
        break;
        }
        walking(front_element, initial_array, color_array, pair_array, my_queue, grid);
        my_queue.pop();
    }

    int count = 1;
    pair<int, int> element = pair_array[goalX][goalY];
    while(element.first != startX || element.second != startY){
        element = pair_array[element.first][element.second];
        count++;
    }
    return count;
  }
  

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int startX = stoi(first_multiple_input[0]);

    int startY = stoi(first_multiple_input[1]);

    int goalX = stoi(first_multiple_input[2]);

    int goalY = stoi(first_multiple_input[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

