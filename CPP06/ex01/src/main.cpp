/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 15:06:17 by magrabko          #+#    #+#             */
/*   Updated: 2025/06/03 14:09:42 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serialize.hpp"

int main(void)
{
    Data *data = new Data;
    data->value = 42;
    std::cout << BOLD "data = "  << data << RESET << std::endl;
    std::cout << "data->value = "  << data->value << std::endl;

    uintptr_t raw = Serialize::serialize(data);
    std::cout << BOLD "\nraw = 0x" << std::hex << raw << std::dec;
    std::cout << RESET "\n" << std::endl;
    
    Data *ptr = Serialize::deserialize(raw);
    
    std::cout << BOLD "ptr = "  << ptr << RESET << std::endl;
    std::cout << "ptr->value = "  << ptr->value << std::endl;

    if (data == ptr)
        std::cout << YELLOW "\nPointers match!" RESET << std::endl;
    
    delete data;
        
    return (0);
}
