#!/bin/bash
(crontab -l ; echo "* * * * * python /home/client.py") | crontab -
