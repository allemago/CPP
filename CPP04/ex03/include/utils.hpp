/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:25:40 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/14 15:41:34 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# define BOLD "\033[1m"
# define GREEN "\e[1;32m"
# define RESET "\033[0m"
# define MAT_DC_MSG "\n✅ mat_2 is a deep copy\n"
# define PLAY_DC_MSG "\n✅ player_1 is a deep copy\n"
# define ICE_DC_MSG "\n✅ iceCopy is a deep copy\n"
# define DEEPCOPY_MSG BOLD "deep copy...\n" RESET
# define PLAY_BEF_MSG "player_1 inventory address before deep copy: "
# define PLAY_AFT_MSG "player_1 inventory address after deep copy: "
# define PLAY_MSG "player_2 inventory address: "
# define CANNOT_EQUIP_MSG "cannot equip a Materia, inventory is full"
# define LIMIT_UNEQUIP_MSG "unequip limit has been reached, restart the game if you want to play again!"
# define INDEX_UNEQUIP_MSG "cannot unequip, select a valid index between 0 and "
# define UNKNOWN_MATERIA_MSG "please choose a valid Materia: [ ice | cure ]"
# define NO_MATERIA_MSG " has no Materia available at this index *"
# define EMPTY_MSG "inventory is empty"
# define EMPTY_MATERIA_MSG "nothing to unequip at this index"
# define CANNOT_LEARN_MSG "cannot learn a Materia, inventory is full"
# define NOTLEARNED_TYPE_MSG "you have to learn a Materia before creating it: learnMateria [ ice | cure ]"
# define UNDEFINED_TYPE_MSG "please choose a valid Materia: [ ice | cure ]"
