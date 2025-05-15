/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:33:20 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/15 17:33:05 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "utils.hpp"

void	deepCopyTest(IMateriaSource* src)
{
	std::cout << "________________________\n" << std::endl;
	std::cout << GREEN "DEEP COPY TEST\n" RESET << std::endl;
	
	// TEST 1
	
	AMateria* mat_1 = src->createMateria("ice");
	AMateria* mat_2 = src->createMateria("ice");

	std::cout << "mat_1 address: " << mat_1 << std::endl;
	std::cout << "mat_2 address: " << mat_2 << std::endl;

	if (mat_1 != mat_2)
		std::cout << MAT_DC_MSG;
		
	delete mat_2;
	
	////////////////////////////////////////////

	std::cout << "________________________\n" << std::endl;

	// TEST 2

	Character*	player_1 = new Character("player_1");
	std::cout << BOLD "player_1 created" RESET << std::endl;
	std::cout << PLAY_BEF_MSG << player_1->getMaterias() << "\n" << std::endl;
	
	Character*	player_2 = new Character("player_2");
	std::cout << BOLD "player_2 created" RESET << std::endl;
	player_2->equip(mat_1);
	
	std::cout << DEEPCOPY_MSG << std::endl;
	*player_1 = *player_2;
	std::cout << PLAY_AFT_MSG << player_1->getMaterias() << std::endl;

	if (player_1 != player_2)
		std::cout << PLAY_DC_MSG;

	delete player_2;
	delete player_1;

	////////////////////////////////////////////

	std::cout << "________________________\n" << std::endl;

	// TEST 3
	
	Ice* iceOrigin = new Ice();
	std::cout << "iceOrigin address: " << iceOrigin << std::endl;
	std::cout << DEEPCOPY_MSG << std::endl;
	Ice* iceCopy = new Ice(*iceOrigin);
	std::cout << "iceCopy address: " << iceCopy << std::endl;

	if (iceOrigin != iceCopy)
		std::cout << ICE_DC_MSG;

	delete iceCopy;
	delete iceOrigin;

	std::cout << "________________________\n" << std::endl;
}

int	main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(NULL);
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("ME_PLAYER");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

 	ICharacter* bob = new Character("BOB_PLAYER");
	me->use(0, *bob);
	me->use(2, *bob);
	me->unequip(2);
	me->use(2, *bob);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->use(2, *bob);
	me->unequip(2);

	deepCopyTest(src);
	
	delete bob;
	delete me;
	delete src;

	return (0);
}
