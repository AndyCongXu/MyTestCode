# Import smtplib for the actual sending function
import sys
import getopt
import smtplib

sender = 'congxv@rayootech.com'
# If there are more than one receiver, you need to ganerate a list. 
# receiver = ['a@xxxx','b@xxxx']
receiver = ['congxv@rayootech.com']  
server = 'smtp.qiye.163.com'
port = '25'
pwd = 'xucong(5493177)'

COMMASPACE = ', '

# Import the email modules we'll need
from email.mime.text import MIMEText

def usage():
    usageStr = '''Usage: SendEmail -c mail_content'''
    #print usageStr

def main(argv):
    # Get the Email content in the "-c" argv
    try:
        opts, args = getopt.getopt(argv, "c:")
    except getopt.GetoptError:
        usage()
        sys.exit(2)

    content = ''

    for opt, arg in opts:
        if opt == '-c':
            content = arg

    #print content

    msg = MIMEText(content)
    
    msg['Subject'] = 'this is the subject'
    msg['From'] = sender
    msg['To'] = COMMASPACE.join(receiver)
    
    s = smtplib.SMTP(server, port)
    s.ehlo()
    s.login(sender, pwd)
    s.sendmail(sender, receiver, msg.as_string())
    s.quit()

if __name__=="__main__":
    main(sys.argv[1:])

