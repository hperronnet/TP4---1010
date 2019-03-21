//
//  Boisson.cpp
//  intra
//
//  Created by Martine Bellaiche on 2019-03-10.
//  Copyright © 2019 Martine Bellaiche. All rights reserved.
//

#include "Boisson.h"
// TODO
Boisson::Boisson (string_view nom, double prix): nom_(nom), prix_(prix)
{
}


string_view Boisson::getNom() const
{ 
	return nom_;
}

void Boisson::setTaxe() 
{
	taxe_ = 0.12*prix_;
}

double Boisson::getTaxe() const {
	return taxe_;
}
double Boisson::getPrix()  const
{
	return prix_;
};


