#include <iostream>
#include <cstring>

using namespace std;

struct ResDataNoteFound {
    char note[3];  // Ajustado para manejar correctamente '\0'
    int positionEscaleChromatic;
    bool band;
};

const int quatityAllNotes = 12;  // Ajustado para el tamaño correcto
const char allNotes[quatityAllNotes][3] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
const int quatityNotesScalesMajorAndMinor = 7;

void getNoteForMakeEscale();
int generateScaleMajor(char const* note);
int generateScaleMinor(char const* note);
ResDataNoteFound searchNote(char const* note);

int main(){
    getNoteForMakeEscale();
    return 0;
}

void getNoteForMakeEscale(){
    char note[3], typeEscale[1];

    cout << "Eyy, amigo ingresa un nota (C, C#, D, etc.)\n:";
    cin >> note; 

    cout << "\nAhora ingresa el tipo de escala\nM: mayor\nE: menor\n:";
    cin >> typeEscale[0];

    switch (typeEscale[0])
    {
    case 'M':
        generateScaleMajor(note);
        break;
    case 'E':
        generateScaleMinor(note);
        break;
    default:
        cout << "\nLa has cagado\n";
        break;
    }
}

ResDataNoteFound searchNote(char const* note){
    ResDataNoteFound dataNote;
    dataNote.positionEscaleChromatic = -1;
    dataNote.band = false;

    for (int i = 0; i < quatityAllNotes; i++) {
        if (strcmp(allNotes[i], note) == 0) {
            strcpy(dataNote.note, allNotes[i]);
            dataNote.positionEscaleChromatic = i;
            dataNote.band = true;
            break;
        }
    }

    return dataNote;
}

int generateScaleMajor(char const* note){
    
    int handlers[quatityNotesScalesMajorAndMinor] = {0, 2, 4, 5, 7, 9, 11};
    char escale[quatityNotesScalesMajorAndMinor][3];

    ResDataNoteFound dataNoteFromFunction = searchNote(note);

    if (dataNoteFromFunction.band) {
        for (int i = 0; i < quatityNotesScalesMajorAndMinor; i++) {
            int pos = (dataNoteFromFunction.positionEscaleChromatic + handlers[i]) % quatityAllNotes;
            strcpy(escale[i], allNotes[pos]);
        }

        cout << "Escala mayor de " << note << ": ";
        for (int i = 0; i < quatityNotesScalesMajorAndMinor; i++) {
            cout << escale[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Nota no encontrada" << endl;
    }

    return 0;
}

int generateScaleMinor(char const* note){
    int handlers[quatityNotesScalesMajorAndMinor] = {0, 2, 3, 5, 7, 8, 10};
    char escale[quatityNotesScalesMajorAndMinor][3];

    ResDataNoteFound dataNoteFromFunction = searchNote(note);

    if (dataNoteFromFunction.band) {
        for (int i = 0; i < quatityNotesScalesMajorAndMinor; i++) {
            int pos = (dataNoteFromFunction.positionEscaleChromatic + handlers[i]) % quatityAllNotes;
            strcpy(escale[i], allNotes[pos]);
        }

        cout << "Escala menor de " << note << ": ";
        for (int i = 0; i < quatityNotesScalesMajorAndMinor; i++) {
            cout << escale[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Nota no encontrada" << endl;
    }

    return 0;
}
