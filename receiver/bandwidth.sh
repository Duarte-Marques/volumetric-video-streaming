#!/bin/bash

TIMESTAMP=$(date +%s)
FILEPATH="experiments/gen-1/$TIMESTAMP.log"
ifstat > "$FILEPATH"