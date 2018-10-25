/* ---------------------------------------------------------------------
 *
 * Copyright (C) 2009 - 2016 by the deal.II authors
 *
 * This file is part of the deal.II library.
 *
 * The deal.II library is free software; you can use it, redistribute
 * it, and/or modify it under the terms of the GNU Lesser General
 * Public License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * The full text of the license can be found in the file LICENSE at
 * the top level of the deal.II distribution.
 *
 * ---------------------------------------------------------------------
 */

#include <deal.II/base/quadrature_lib.h>
#include <deal.II/base/utilities.h>

#include <fstream>
#include <iostream>

using namespace dealii;


template <int dim>
void render(Quadrature<dim> &q)
{
  if (dim==2)
    std::cout << "set xrange [0:1]\n"
              << "set yrange [0:1]\n"
              << "set term pngcairo crop\n"
              << "set output 'output.png'\n"
              << "set size square\n"
              << "set key off\n";

  std::cout << "plot '-' w p pt 7\n";

  unsigned int N = q.size();
  for (unsigned int i=0; i<N; ++i)
    std::cout << q.point(i) << std::endl;
  std::cout << "e" << std::endl;

}




void test()
{
  QGauss<2> q(3);
  render(q);



}


int main()
{
  test();

  return 0;
}
