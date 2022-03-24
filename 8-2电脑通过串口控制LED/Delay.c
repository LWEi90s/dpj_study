
//延时函数
void Delay(unsigned int xms)		//@12.000MHz 1ms
{
	unsigned char i, j;
	while(xms)
	{
				i = 2;
			j = 239;
			do
			{
				while (--j);
			} while (--i);
			xms--;
  }
}