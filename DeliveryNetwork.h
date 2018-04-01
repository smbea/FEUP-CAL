//
// Created by Beatriz Mendes on 29/03/2018.
//

#ifndef CAL_PROJ_DELIVERYNETWORK_H
#define CAL_PROJ_DELIVERYNETWORK_H

#include "Graph.h"
#include "GPS.h"
#include <string>
#include <unordered_map>
#include "Client.h"
#include "Supermarket.h"
#include "graphviewer.h"

class DeliveryNetwork {
	
	Graph graph;
	GraphViewer *gv;

	std::unordered_map<int, Client> clients;
	std::unordered_map<int, Supermarket> supermarkets;

public:
	
	bool loadGraph(std::string aname, std::string bname, std::string cname);

	Graph getGraph() const;
};


#endif //CAL_PROJ_DELIVERYNETWORK_H
