## Tips

If issue with COM ports,

```bash
sudo adduser $(whoami) dialout
 
sudo chmod a+rw /dev/ttyUSB0 # Or other port number
```