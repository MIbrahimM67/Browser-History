#pragma once
#include <iostream>
#include "Tab.h"
class BrowserHistroy {
	tabs * current;

public:
	BrowserHistroy()       // default construct takes the current pointer to a homepage
	{
		current = new tabs;
		current->URL = "Homepage.com";
		current->next = nullptr;
		current->prev = nullptr;
	}
	~BrowserHistroy() // destroys all the tabs to avoid memory leak
	{
		tabs* temp = current;
		while (temp->prev != nullptr)
		{
			temp = temp->prev;
		}
		current = temp->next;
		while (current != nullptr)
		{
			delete temp;
			temp = current;
			current = current->next;
		}

	}
	void visit(const std::string &url) 
	{
		if (current->next != nullptr) // if there is no next node, this will then move the pointer to the end and inserts a tab there
		{
			tabs* temp=current;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = new tabs;
			temp->next->prev = temp;
			temp->next->URL = url;
			current = temp->next;
			current->next = nullptr;
		}
		else if (current->next == nullptr)
		{
			current->next = new tabs;
			current->next->prev = current;
			current = current->next;
			current->URL = url;
			current->next = nullptr;
		}

	}

	std::string back(const int &steps) 
	{
		for (int i = 0; i < steps; i++)
		{
			if (this->current->prev == nullptr)
			{
				std::cout << "You Cannot Move back any further,your current tab is " << std::endl;
				break;
		    }
			else
			this->current = this->current->prev;
		}
		return this->current->URL;
	}

	std::string forward(const int&steps)
	{
		for (int i = 0; i < steps; i++)
		{
			if (this->current->next ==nullptr)
			{
				std::cout << "You Cannot Move forward any further, your current tab is " << std::endl;
				break;
			}
			this->current = current->next;
		}
		return this->current->URL;
	}


};