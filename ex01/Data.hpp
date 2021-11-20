/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 21:37:35 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/20 21:38:32 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

class Data
{
	int	_num;

public:
	// orthodox canonical form
	Data(int num = 0);
	Data(const Data& other);
	Data&	operator=(const Data& other);
	~Data();

	// methods
	int	num() const;
};

#endif /* DATA_HPP */
