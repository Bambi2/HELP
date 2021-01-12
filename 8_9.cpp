#include <iostream>
#include <stack>
using namespace std;

const int V = 5; //Кол-во вершин

int arr[V][V] =
    {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 0}}; //матрица смежности

bool visited[V]; //массив пройденных вершин
int previ[V];    //массив родительских вершин

void dfs(int node)
{
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && arr[node][i] == 1)
        {
            visited[node] = true;
            previ[i] = node;
            dfs(i);
        }
    }
}

int main()
{
    int start; //начальная точка
    int end;   //конечная точка

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    cout << "Enter the start node: ";
    cin >> start;

    cout << "Enter the end node: ";
    cin >> end;

    visited[start] = true;
    previ[start] = -1;

    int reply;
    cout << "Do you want to use recursion on not? (0 - 'yes'; 1 - 'no')" << endl;
    cin >> reply;
    if (reply == 0)
    {
        dfs(start);
    }
    else if (reply == 1)
    {
        stack<int> s;
        s.push(start);

        while (!s.empty())
        {
            int current = s.top();

            for (int i = 0; i < V; i++)
            {
                if (!visited[i] && arr[current][i] == 1)
                {
                    s.push(i);
                    visited[i] = true;
                    previ[i] = current;
                }
                else
                {
                    s.pop();
                    break;
                }
            }
        }
    }
    else
    {
        cout << "Invalid data" << endl;
        return 0;
    }

    int dne = end;
    int count = 0;

    do
    {
        count++;
        dne = previ[dne];
    } while (dne != previ[start]);

    int *path = new int[count];
    path[0] = end;
    int i = 1;

    do
    {
        path[i] = previ[end];
        i++;
        end = previ[end];
    } while (end != start);

    while (i >= 0)
    {
        cout << path[i] << " ";
        i--;
    }
    cout << endl;
}
