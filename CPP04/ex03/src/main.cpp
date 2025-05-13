/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:33:20 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/13 17:39:34 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "test.hpp"

void	deepCopyTest(IMateriaSource* src)
{
	std::cout << BOLD "\nDEEP COPY TEST\n" RESET << std::endl;
	
	// TEST 1
	
	AMateria* mat_1 = src->createMateria("ice");
	AMateria* mat_2 = src->createMateria("ice");

	std::cout << "mat_1: " << mat_1 << std::endl;
	std::cout << "mat_2: " << mat_2 << std::endl;

	if (mat_1 != mat_2)
		std::cout << MAT2_DC_MSG;
		
	delete mat_2;
	
	////////////////////////////////////////////

	std::cout << std::endl;

	// TEST 2

	Character*	player_1 = new Character("player_1");
	std::cout << BOLD "player_1 created" RESET << std::endl;
	std::cout << PLAY1_BEF_MSG << player_1->getMaterias() << "\n" << std::endl;
	
	Character*	player_2 = new Character("player_2");
	std::cout << BOLD "player_2 created" RESET << std::endl;
	player_2->equip(mat_1);
	std::cout << PLAY2_MSG << player_2->getMaterias() << std::endl;
	
	std::cout << DEEPCOPY_MSG << std::endl;
	*player_1 = *player_2;
	std::cout << PLAY1_AFT_MSG << player_1->getMaterias() << std::endl;

	if (player_1 != player_2)
		std::cout << PLAY1_DC_MSG;

	std::cout << std::endl;

	delete player_2;
	delete player_1;
}

int	main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(2);

	me->use(0, *bob);
	
	deepCopyTest(src);

	delete bob;
	delete me;
	delete src;
	
	return (0);
}
