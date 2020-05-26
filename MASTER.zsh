#! /bin/zsh

channels="ee mumu"

outPath="~/Research/atlas-hi/ZTrackAnalysis/rootFiles/Jewel/"

for iJob in {89..96..4}
do
  for channel in $( echo "$channels")
  do
    for iSubJob in {${iJob}..$((iJob+3))}
    do
      parameterFile="parameterFiles/z${channel}_jet_in_medium_highPt_${iSubJob}.dat"
      jewel-2.2.0-simple ${parameterFile} &
    done
    wait

    for iSubJob in {${iJob}..$((iJob+3))}
    do
      parameterFile="parameterFiles/z${channel}_jet_in_medium_highPt_${iSubJob}.dat"
      fileTemplate="z${channel}_jet_medium_highPt_nevt_10000_job${iSubJob}"
      ./bin/HepMC2TTree eventFiles/${fileTemplate}.hepmc ${outPath}/${fileTemplate}.root true
    done

  done
done


for iJob in {89..96..4}
do
  for channel in $( echo "$channels")
  do
    for iSubJob in {${iJob}..$((iJob+3))}
    do
      parameterFile="parameterFiles/z${channel}_jet_in_vacuum_highPt_${iSubJob}.dat"
      jewel-2.2.0-vac ${parameterFile} &
    done
    wait

    for iSubJob in {${iJob}..$((iJob+3))}
    do
      parameterFile="parameterFiles/z${channel}_jet_in_vacuum_highPt_${iSubJob}.dat"
      fileTemplate="z${channel}_jet_vacuum_highPt_nevt_10000_job${iSubJob}"
      ./bin/HepMC2TTree eventFiles/${fileTemplate}.hepmc ${outPath}/${fileTemplate}.root true
    done

  done
done
