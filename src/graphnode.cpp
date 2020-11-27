#include "graphedge.h"
#include "graphnode.h"
#include <iostream>
#include "chatlogic.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
}

GraphNode::GraphNode(const GraphNode& graphnode)
{
    for(const auto& i : graphnode._childEdges)
    {
        this->_childEdges.emplace_back(new GraphEdge(*i));
    }

    for(const auto k : graphnode._parentEdges)
    {
        this->_parentEdges.emplace_back(new GraphEdge(*k));
    }

    this->_chatBot = graphnode._chatBot;
    this->_id = graphnode._id;
    for(const auto i: graphnode._answers)
    {
        this->_answers.emplace_back(i);
    }

}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> childEdge)
{
    _childEdges.push_back(std::move(childEdge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    _chatBot = std::move(chatbot);
    _chatBot.GetChatLogicHandle()->setChatBot(&_chatBot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(this->_chatBot));
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}
