/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:25:40 by magrabko          #+#    #+#             */
/*   Updated: 2025/05/14 10:15:26 by magrabko         ###   ########.fr       */
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
# define PLAY_BEF_MSG "player_1 inventory (address) before deep copy: "
# define PLAY_AFT_MSG "player_1 inventory (address) after deep copy: "
# define PLAY_MSG "player_2 inventory (address): "