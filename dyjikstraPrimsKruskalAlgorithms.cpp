//#include <iostream>
//using namespace std;
//
//class graph
//{
//public:
//    int noOfvertices;
//    int array[100][100];
//    int sum;
//
//    graph(int novertices)
//    {
//        /////  Constructor setting the number of vertices passed by user  /////
//        this->noOfvertices = novertices;
//        sum = 0;
//
//        ///---------- Initialize the adjacency matrix to all zeros ----------///
//        for (int i = 0; i < noOfvertices; i++)
//        {
//            for (int j = 0; j < noOfvertices; j++)
//            {
//                array[i][j] = 0;
//            }
//        }
//    }
//
//    void inputMatrix()
//    {
//        ///// Entering the entries of the matrix /////
//        cout << "Enter the adjacency matrix (use 0 for no edge):\n";
//        for (int i = 0; i < noOfvertices; i++)
//        {
//            for (int j = 0; j < noOfvertices; j++)
//            {
//                cout << "[" << i << "][" << j << "]" << " : ";
//                cin >> array[i][j];
//            }
//        }
//    }
//
//    void primsMst()
//    {
//        int key[100];
//        bool mst[100];
//        int parent[100];
//
//        for (int i = 0; i < noOfvertices; i++)
//        {
//
//            ///---------- key[] stores minimum weights----------///
//            ///---------- mst[] keeps track of vertices included in MST ----------///
//            key[i] = 99999;
//            mst[i] = false;
//        }
//
//
//        key[0] = 0;
//        parent[0] = -1;
//        ///---------- Root of the MST does not have a parent that is why initiating it with -1 ----------///
//
//        for (int i = 0; i < noOfvertices; i++)
//        {
//
//            ///---------- Finding the vertex with the smallest key value not yet included in MST ----------//
//            int minKey = 99999, u = -1;
//            for (int j = 0; j < noOfvertices; j++)
//            {
//                if (!mst[j] && key[j] < minKey)
//                {
//                    minKey = key[j];
//                    u = j;
//                }
//            }
//            ///---------- Include the selected vertex in the MST ----------///
//            mst[u] = true;
//
//            for (int i = 0; i < noOfvertices; i++)
//            {
//
//                if (array[u][i] && !mst[i] && array[u][i] < key[i])
//                {
//                    parent[i] = u;
//                    key[i] = array[u][i];
//                }
//            }
//        }
//        cout << "Prims's MST:\n";
//        cout << "Edge    Weight\n";
//        for (int i = 1; i < noOfvertices; ++i)
//        {
//            cout << parent[i] << " - " << i << "    " << array[i][parent[i]] << "\n";
//            sum += array[i][parent[i]];
//        }
//        cout << "Minimum cost using Prims's: " << sum << endl;
//    }
//
//    void display()
//    {
//        for (int i = 0; i < noOfvertices; i++)
//        {
//            for (int j = 0; j < noOfvertices; j++)
//            {
//                cout << array[i][j] << " | ";
//            }
//            cout << endl;
//        }
//    }
//
//    struct Edge
//    {
//        int src, dest, weight;
//    };
//
//    void sortedges(Edge edges[], int noofedges)
//    {
//        ///---------- Function to sort edges based on weight using bubble sort ----------///
//        for (int i = 0; i < noofedges - 1; i++)
//        {
//            for (int j = 0; j < noofedges - i - 1; j++)
//            {
//                if (edges[j].weight > edges[j + 1].weight)
//                {
//                    Edge temp = edges[j];
//                    edges[j] = edges[j + 1];
//
//                    edges[j + 1] = temp;
//                }
//            }
//        }
//    }
//    int findParent(int vertex, int parent[])
//    {
//        if (parent[vertex] == vertex)
//            return vertex;
//        return parent[vertex] = findParent(parent[vertex], parent);
//    }
//
//
//    void unionSets(int u, int v, int parent[], int rank[]) {
//        int rootU = findParent(u, parent);
//        int rootV = findParent(v, parent);
//
//        if (rank[rootU] < rank[rootV]) {
//            parent[rootU] = rootV;
//        }
//        else if (rank[rootU] > rank[rootV]) {
//            parent[rootV] = rootU;
//        }
//        else {
//            parent[rootV] = rootU;
//            rank[rootU]++;
//        }
//    }
//
//    void kruskalMST(int matrix[100][100], int vertices)
//    {
//        Edge edges[1000];
//        int edgeCount = 0;
//
//        // Extract all edges from the adjacency matrix
//        for (int i = 0; i < vertices; i++) {
//            for (int j = i + 1; j < vertices; j++) { // Avoid duplicate edges
//                if (matrix[i][j] != 0) {
//                    edges[edgeCount].src = i;
//                    edges[edgeCount].dest = j;
//                    edges[edgeCount].weight = matrix[i][j];
//                    edgeCount++;
//                }
//            }
//        }
//
//        //Sort edges by weight
//        sortedges(edges, edgeCount);
//
//        int parent[100], rank[100];
//
//        for (int i = 0; i < vertices; i++)
//        {
//            ///---------- Each vertex is initially its own parent ----------///
//            parent[i] = i;
//            rank[i] = 0;
//        }
//
//        int mstWeight = 0;
//        cout << "Kruskal's MST:\n";
//        cout << "Edge    Weight\n";
//
//        int selectedEdges = 0;
//        for (int i = 0; i < edgeCount && selectedEdges < vertices - 1; i++)
//        {
//            int source = edges[i].src;
//            int destination = edges[i].dest;
//            int weight = edges[i].weight;
//            ///----- Finding parent of both of the nodes -----///
//            int rootU = findParent(source, parent);
//            int rootV = findParent(destination, parent);
//
//            ///----- Checking if these belong to different components -----///
//            if (rootU != rootV)
//            {
//                cout << source << " - " << destination << "    " << weight << "\n";
//                mstWeight += weight;
//                unionSets(rootU, rootV, parent, rank);
//                selectedEdges++;
//            }
//        }
//
//        cout << "Minimum cost using Kruskal's: " << mstWeight << endl;
//    }
//
//};
//
//int main()
//{
//    while (true) {
//        int num;
//        cout << "Enter the number of vertices : ";
//        cin >> num;
//
//        graph g(num);
//
//
//        g.inputMatrix();
//
//        cout << "Displaying the adjacency matrix..\n";
//        g.display();
//        g.kruskalMST(g.array, num);
//        cout << endl;
//
//        g.primsMst();
//
//        system("pause");
//
//
//
//    }
//  
//
//
//    return 0;
//}
