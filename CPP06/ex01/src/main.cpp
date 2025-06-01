/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 15:06:17 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/01 15:50:42 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serialize.hpp"

int main(void)
{
    Data data;
    data.value = 42;
    std::cout << BOLD "data = "  << &data << RESET << std::endl;
    std::cout << "data.value = "  << data.value << std::endl;
    
    uintptr_t raw = Serialize::serialize(&data);
    std::cout << "\nraw = " << raw << "\n" << std::endl;
    
    Data *ptr = Serialize::deserialize(raw);
    
    std::cout << BOLD "ptr = "  << ptr << RESET << std::endl;
    std::cout << "ptr.value = "  << ptr->value << std::endl;

    if (&data == ptr)
        std::cout << GREEN "\nPointers match!" BOLD << std::endl;
    
    return (0);
}
