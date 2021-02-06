class Solution(object):
    def validIPAddress(self, IP):
        """
        :type IP: str
        :rtype: str
        """
        if IP.count('.')==3:
            return self.ipv4(IP)
        elif IP.count(':')==7:
            return self.ipv6(IP)
        else:
            return "Neither"
    def ipv4(self,IP):
        l = IP.split('.')
        for i in l:
            if len(i)==0 or len(i)>3:
                return "Neither"
            if i[0]=='0' and len(i)!=1 or not i.isdigit() or int(i)>255:
                return "Neither"
        return "IPv4"
    def ipv6(self,IP):
        l = IP.split(':')
        hexdigits = '0123456789abcdefABCDEF'
        for i in l:
            if len(i)==0 or len(i)>4 or not all(c in hexdigits for c in i):
                return "Neither"
        return "IPv6"
s = Solution()
print(s.validIPAddress("172.16.254.1"))