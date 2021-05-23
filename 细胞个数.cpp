#include<iostream>
#include<queue>
using namespace std;
struct node{
	int x, y;
};

int main(){
	int m, n;
	cin >> m >> n;
	char cell[50][80];
	for(int i = 0; i < m; i++){
		cin >> cell[i];
	}

    cout << endl;
    
    node n1[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    queue<node> q;
    int count = 0;
    node newNode;
    for(int x0 = 0; x0 < m; x0++){
    	for(int y0 = 0; y0 < n; y0++){
    		if(cell[x0][y0] == '0') continue;
    		count++;
			q.push((node){x0, y0});
			cell[x0][y0] = '0';
			while(!q.empty()){
				cout << " 当前队首元素坐标： " << q.front().x << " " << q.front().y << ":\n";
				for(int i = 0; i< 4; i++){
					newNode.x = q.front().x + n1[i].x;
					newNode.y = q.front().y + n1[i].y;
					cout <<newNode.x << " " << newNode.y << ":";
					if(newNode.x >= 0 && newNode.x < m
			        && newNode.y >= 0 && newNode.y < n
					&& cell[newNode.x][newNode.y] != '0') {
						q.push(newNode);
						cell[newNode.x][newNode.y] = '0';
						cout << "入队";
					} else cout << "不在范围或已经被吃掉"； 
					cout << endl;
				}
				q.pop();
			}
		    for(int i = 0; i < m; i++){
				cout << cell[i] << endl;
			}
			
			cout << "_______________________" << endl;     		
		}
	}
    cout << count;
    
	
    return 0;
}
