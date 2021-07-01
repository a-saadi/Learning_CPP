/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi <asaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 10:18:07 by asaadi            #+#    #+#             */
/*   Updated: 2021/07/01 18:05:34 by asaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad(): _units(nullptr)
{
}

Squad::Squad(Squad const & orig)
{
	*this = orig;
	return ;
}

void	Squad::clearing_squad()
{
	t_list *tmp;
	while (this->_units)
	{
		tmp = this->_units;
		this->_units = this->_units->next;
		delete tmp->unit;
		delete tmp;
	}
}

Squad::~Squad()
{
	clearing_squad();
}

Squad & Squad::operator=(Squad const & orig)
{
	if (this != &orig)
	{
		this->clearing_squad();
		Squad *_new = new Squad;
		t_list *tmp = orig._units;
		while (orig._units)
		{
			ISpaceMarine *_newUnit = tmp->unit;
			push(_newUnit);
			tmp = tmp->next;
		}
		return *_new;
	}
	return *this;
}

int Squad::getCount() const
{
	int count = 0;
	t_list *tmp = this->_units;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return count;
}

ISpaceMarine* Squad::getUnit(int nUnit) const
{
	t_list *tmp = this->_units;
	for (int i = 0; i < this->getCount(); i++)
	{
		if (i == nUnit)
			break ;
		tmp = tmp->next;
	}
	return tmp->unit;
}

int Squad::push(ISpaceMarine* unit)
{
	if (!this->_units)
	{
		this->_units = new t_list;
		this->_units->unit = unit;
		this->_units->next = NULL;
		return this->getCount();
	}
	t_list *tmp = this->_units;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new t_list;
	tmp->next->unit = unit;
	tmp->next->next = NULL;
	return this->getCount();
}
