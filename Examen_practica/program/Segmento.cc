
#include "Segmento.hh"
#include <iostream>

using namespace std;

Segmento::Segmento() {
  u = Ubicacion(-1,-1,-1);
  l = 0;
}

Segmento::Segmento(const Ubicacion &u, int l) {
  this->u = u;
  this->l = l;
}

Segmento::Segmento(const Segmento &s) {
  u = s.u;
  l = s.l;
}

Segmento::~Segmento() {
}

Ubicacion Segmento::ubic() const {
  return u;
}

int Segmento::longitud() const {
  return l;
}

void Segmento::print() const {
  cout << "(";
  u.print();
  cout << "," << l << ")";
}

Segmento& Segmento::operator=(const Segmento &s) {
  if (this != &s) {
    u = s.u;
    l = s.l;
  }
  return *this;
}

bool Segmento::operator==(const Segmento& s) const {
  return ((l == s.l) and (u == s.u));
}

bool Segmento::operator!=(const Segmento& s) const {
  return not(*this == s);
}

//Prioridad estandar: longitud < Ubicacion 
/*
bool Segmento::operator<(const Segmento& s) const
{
  return ((l < s.l) or
          ((l == s.l) and (u < s.u)));
}
*/

//Nueva prioridad: hilera < longitud < piso < plaza
bool Segmento::operator<(const Segmento& s) const
{
  return ((u.hilera() < s.u.hilera()) or 
         ((u.hilera() == s.u.hilera()) and (l < s.l)) or
         ((u.hilera() == s.u.hilera()) and (l == s.l) and (u.piso() < s.u.piso())) or
         ((u.hilera() == s.u.hilera()) and (l == s.l) and (u.piso() == s.u.piso()) and (u.plaza() < s.u.plaza())));
}

bool Segmento::operator<=(const Segmento& s) const {
  return *this < s or s == *this;
}

bool Segmento::operator>=(const Segmento& s) const {
  return not (*this < s);
}

bool Segmento::operator>(const Segmento& s) const {
  return *this >= s and *this != s;
}


