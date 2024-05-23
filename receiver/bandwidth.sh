#!/bin/bash

TIMESTAMP=$(date +%s)
FILEPATH="build/$TIMESTAMP.log"
ifstat -t 0.5 > "$FILEPATH"