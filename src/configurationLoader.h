class ConfigurationLoader 
{
    public:
        ConfigurationLoader(const std::string& filepath);

        unsigned int getWindowWidth();
        unsigned int getWindowHeight();

    private:
        unsigned int m_windowWidth = 100u;
        unsigned int m_windowHeight = 100u;

        void setWindowMembers();
};