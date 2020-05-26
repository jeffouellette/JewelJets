#! /bin/zsh

channels="ee mumu"

nEvt=10000

for iJob in {89..96}
do
  for channel in $( echo "$channels")
  do
    parameterFile="parameterFiles/z${channel}_jet_in_medium_highPt_${iJob}.dat"

    echo "LOGFILE logs/z${channel}_jet_medium_highPt_nevt_10000_job${iJob}.log" > ${parameterFile}
    echo "HEPMCFILE eventFiles/z${channel}_jet_medium_highPt_nevt_10000_job${iJob}.hepmc" >> ${parameterFile}

    if [[ "${channel}" == "ee" ]]
    then
      echo "NJOB ${iJob}" >> ${parameterFile}
    else if [[ "${channel}" == "mumu" ]]
      echo "NJOB $(( iJob + 100 ))" >> ${parameterFile}
    fi

    echo "NEVENT ${nEvt}" >> ${parameterFile}
    echo "SQRTS 5020" >> ${parameterFile}
    echo "PROCESS PPZJ" >> ${parameterFile}

    if [[ "${channel}" == "ee" ]]
    then
      echo "CHANNEL ELEC" >> ${parameterFile}
    else if [[ "${channel}" == "mumu" ]]
      echo "CHANNEL MUON" >> ${parameterFile}
    fi

    echo "PTMIN 25" >> ${parameterFile}
    echo "PTMAX -1" >> ${parameterFile}
    echo "ETAMAX 2.5" >> ${parameterFile}
    echo "WEXPO 0" >> ${parameterFile}

      
    echo "KEEPRECOILS T" >> ${parameterFile}
    echo "WRITESCATCEN T" >> ${parameterFile}
    echo "WRITEDUMMIES T" >> ${parameterFile}
    echo "MEDIUMPARAMS medium.params.dat" >> ${parameterFile}

  done
done


for iJob in {89..96}
do
  for channel in $( echo "$channels")
  do
    parameterFile="parameterFiles/z${channel}_jet_in_vacuum_highPt_${iJob}.dat"

    echo "LOGFILE logs/z${channel}_jet_vacuum_highPt_nevt_10000_job${iJob}.log" > ${parameterFile}
    echo "HEPMCFILE eventFiles/z${channel}_jet_vacuum_highPt_nevt_10000_job${iJob}.hepmc" >> ${parameterFile}

    if [[ "${channel}" == "ee" ]]
    then
      echo "NJOB $(( iJob + 200 ))" >> ${parameterFile}
    else if [[ "${channel}" == "mumu" ]]
      echo "NJOB $(( iJob + 300 ))" >> ${parameterFile}
    fi

    echo "NEVENT ${nEvt}" >> ${parameterFile}
    echo "SQRTS 5020" >> ${parameterFile}
    echo "PROCESS PPZJ" >> ${parameterFile}

    if [[ "${channel}" == "ee" ]]
    then
      echo "CHANNEL ELEC" >> ${parameterFile}
    else if [[ "${channel}" == "mumu" ]]
      echo "CHANNEL MUON" >> ${parameterFile}
    fi

    echo "PTMIN 25" >> ${parameterFile}
    echo "PTMAX -1" >> ${parameterFile}
    echo "ETAMAX 2.5" >> ${parameterFile}
    echo "WEXPO 0" >> ${parameterFile}

      
    echo "KEEPRECOILS T" >> ${parameterFile}
    echo "WRITESCATCEN T" >> ${parameterFile}
    echo "WRITEDUMMIES T" >> ${parameterFile}
    echo "MEDIUMPARAMS medium.params.dat" >> ${parameterFile}

  done
done
