#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

//CONSTRUCTORES
Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
Employee* employee_newParametrosCorrespondientes(int* id,char* nombre,int* horasTrabajadas, int* sueldo);

int employee_delete(Employee* this);

//COMPARADORES
int employee_compareById(void* employee1, void* employee2);
int employee_compareByNombre(void* employee1, void* employee2);
int employee_compareByHorasTrabajadas(void* employee1, void* employee2);
int employee_compareBySueldo(void* employee1, void* employee2);


int employee_showOneEmployee(Employee* auxEmpleado, int indice);

//SETTERS Y GETTERS
int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);



#endif // employee_H_INCLUDED
