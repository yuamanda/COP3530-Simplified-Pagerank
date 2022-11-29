// Created by Amanda Yu on 11/12/22.
//

#ifndef UNTITLED1_ADJACENCYLIST_H
#define UNTITLED1_ADJACENCYLIST_H

#include <map>
#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;

class AdjacencyList
{
private:
    // map to store the out degree
    map<string, int> outDegreeMap;

    // map to store the in degree
    map<string, vector<string>> inDegreeMap;

    // map to store websites with their respective ranks
    map<string, float> pageRankMap;

public:
    // prints the page rank of all pages after p powerIterations
    // in ascending alphabetical order of webpages and rounding rank to two decimal places
    void PageRank(int n)
    {
        // initialize page rank to 1/v as r(0)
        for(auto &webpage: inDegreeMap)
        {
            pageRankMap[webpage.first] = 1.0f / (float)inDegreeMap.size();
        }

        // map to hold old page ranks until the next iteration
        map<string, float> newPageRankMap;

        // for the number of power iterations, find the page rank
        for(int i = 1; i < n; i++)
        {
            // set the new page rank map equal to page rank map
            newPageRankMap = pageRankMap;

            // for each webpage, update the new page rank map
            for(auto &webpage : inDegreeMap)
            {
                // initialize the sum of page rank for each webpage
                float sum = 0.0f;

                // for each webpage, calculate the page rank
                for(auto &link : webpage.second)
                {
                    // sum = (1 / out degree of j) * page rank of i
                    sum += (1.0f / (float)outDegreeMap.find(link)->second) * pageRankMap[link];
                }

                // update the new page rank with the webpage and corresponding page rank
                newPageRankMap[webpage.first] = sum;
            }
            // update the page rank
            pageRankMap = newPageRankMap;
        }

        // iterator to go through each vertex
        map<string, float>::iterator pageRankIterator;

        // prints out the ranks
        for(pageRankIterator = pageRankMap.begin(); pageRankIterator != pageRankMap.end(); pageRankIterator++)
        {
            cout << setprecision(2) << fixed << pageRankIterator->first << " " << pageRankIterator->second;
            cout << "\n";
        }
    }

    // insert edges into the graph
    void insertEdge(string from, string to)
    {
        // push from and to value into the maps
        outDegreeMap[from] += 1;
        inDegreeMap[to].push_back(from);

        // if "from" isn't in the graph, add it as a string with an empty value of 0
        if(outDegreeMap.find(to) == outDegreeMap.end())
        {
            outDegreeMap[to] = 0;
        }

        // if "to" isn't in the graph, add it as a string with an empty vector of {}
        if(inDegreeMap.find(from) == inDegreeMap.end())
        {
            inDegreeMap[from] = {};
        }
    }
};

#endif //UNTITLED1_ADJACENCYLIST_H
