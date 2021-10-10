#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <cstring>

// verify the validity of positions
bool is_valid(int& k, int& s, int& M, int& N) {
  return (k >= 1) && (k <= M) && (s >= 1) && (s <= N);
} 

// every location is a node
struct node {
  int x, y; 
  int dist=0;
  bool visited = false;
};

// return x, y cordinate
node cordinates(std::string& pos) {
  std::vector<char> x_axis = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
  node nd;
  for (unsigned int i=1; i < x_axis.size()+1; i++) {
    if (x_axis[i-1] == pos[0]) {
      nd.x = i;
      nd.y = pos[1] - '0';
      return nd;
    }
  }
}

int shortest_path_between_two_nodes(node& src, node& dst, int& n) {
  int M = n; int N = n;
  std::vector<int> dx {-2, -1, 1, 2, -2, -1, 1, 2};
  std::vector<int> dy {-1, -2, -2, -1, 1, 2, 2, 1};

  bool visited[M+1][N+1];
  std::memset(visited, false, sizeof(visited));
  std::queue<node> q;
  src.visited = true;
  q.push(src);

  while (!q.empty()) {
    node t = q.front();
    q.pop();

    if ((t.x == dst.x) && (t.y == dst.y))
      return t.dist;
    for (int i=0; i < 8; i++) {
      int next_x = t.x + dx[i];
      int next_y = t.y + dy[i];

      if (is_valid(next_x, next_y, M, N) && !visited[next_x][next_y]) {
        node st;
        st.x = next_x; st.y = next_y; st.dist += 1;
        visited[next_x][next_y] = true;
        q.push(st); 
      }
    }
  }
  return -1;
}

void steps(int& n, int& N, std::string& knight_pos, std::vector<std::string>& locations) {
  node k_node = cordinates(knight_pos);
  for (std::string& xy: locations) {
    // convert to a node
    node pawn = cordinates(xy);
    int sp = shortest_path_between_two_nodes(k_node, pawn, n);
    std::cout << sp << std::endl;
  }
}

int main() {
  int n, N;
  std::string knight_pos, pos, buf;
  std::vector<std::string> locations;
  
  // take n, N, knight's position
  std::cin >> n >> N >> knight_pos;
  std::cin.ignore();

  // location of N pawns
  std::getline(std::cin, pos);
  std::stringstream ss(pos);
  std::vector<std::string>::iterator ii;
  while (ss >> buf)
   locations.push_back(buf); 

  steps(n, N, knight_pos, locations);
}

// not working