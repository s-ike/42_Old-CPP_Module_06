/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:19:07 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/20 16:43:48 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <string>

class Convert
{
	std::string	_input;
	bool		_has_point;
	bool		_is_special;
	bool		_is_valid;
	double		_d;

	// orthodox canonical form
	Convert();

	// methods
	bool	is_valid_input();
	void	modify_input();
	void	to_double();

	void	display_all_impossible();
	void	put_char();
	void	put_int();
	void	put_float();
	void	put_double();

public:
	// orthodox canonical form
	Convert(const std::string& input);
	Convert(const Convert& other);
	Convert&	operator=(const Convert& other);
	~Convert();

	// methods
	void	display_result();
};

#endif /* CONVERT_HPP */
