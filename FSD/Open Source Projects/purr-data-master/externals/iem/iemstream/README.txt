stream - external library for streaming

Momentan ein Object amp~ zur Wiedergabe von ogg-Streams.

Die Idee stammt von readanysf~ (August Black), wurde aber v�llig neu implementiert. 
Ein paar unwichtige Code-Schnippsel sind noch drin, werden aber auch neu geschrieben.


Features (im Vergleich pdogg and readanysf~):
- Mehrkanalf�higkeit
- Genau dosierbare Pufferung
- nur ein thread f�r Datenempfang und Decodierung 
- Stream-Resampling, wenn n�tig


Abh�ngigkeiten:
- OGG und Vorbis
- libsamplerate

Bedienung:
[amp~ n] erzeugt ein Objekt mit n Signal-Outlets. Der Stream kann eine andere Kanalzahl haben.
�berz�hlige Stream-Kan�le werden ignoriert, �berz�hlige Outlets haben 0~-Signale.

Messages:
[connect URI( ... Verbinde zu Server:Port/Mountpoint und starte Wiedergabe
[disconnect( .... Stoppe Wiedergabe
[strbuf samples ( ... Stream-Buffer-Gr��e in Samples (default 10000)
[strchunk samples ( ... Samples die auf einmal vom Socket gelesen werden (default 500)
[strthresh ratio ( ... Threshold 0...1 unter welchem Anteil der Buffer-F�llung nachgeladen wird. (default 0.95)

[debug 0/1 ( .... Debug-Output zur Konsole


Probleme:
resampling funktioniert nicht einwandfrei

LICENCE: GPL
 see LICENCE.txt
