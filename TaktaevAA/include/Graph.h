#pragma once
class Edge
{
	int n;
	int e;
	int weight;
public:
	Edge(int, int, int);
	bool operator<(const Edge&) const;
	bool operator>(const Edge&) const;
	bool operator<=(const Edge&) const;
	bool operator>=(const Edge&) const;
	bool operator==(const Edge&) const;
	bool operator!=(const Edge&) const;
};

class Graph
{
	Edge* edges;
	int n;
	int m;
public:
	Graph();
	Graph(int, int);
	~Graph();


};