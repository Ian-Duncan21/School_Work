package cs430.a6;

import cs430.a6.entity.*;

import java.sql.SQLException;

import java.sql.Connection;

import java.sql.DriverManager;

import java.sql.PreparedStatement;

import java.sql.CallableStatement;

import java.sql.ResultSet;

import java.util.ArrayList;

/**
 * Implement the methods as per the instructions given in the write up
 * and in the comments below.
 * Please do not change the signatures of these methods.
 * For testing, a tester class will be implemented which will create
 * and instance of this class (using the default constructor) and invoke
 * the methods.
 */
public class Stub {
    private Connection conn;
    public static void main(String args[]){
        Stub st = new Stub();
        st.init();
    }

    // Do not change or remove the default constructor.
    public Stub() {
        
    }

    // Write initializing logic if there is any. This method will be
    // called immediately following the constructor call.
    public void init(){
        String db = "jdbc:postgresql://faure.cs.colostate.edu:5432/iandunc";
        // Database name to access
        String dbUsername = "iandunc";
        String dbPassword = "832037648";
        try {
            Class.forName("org.postgresql.Driver");
        } 
        catch (ClassNotFoundException e) {
            System.out.println("DRIVER NOT FOUND");
            e.printStackTrace();
        }
        try {
            //Connection conn;
            conn = DriverManager.getConnection(db, dbUsername, dbPassword);
            System.out.println("CONNECTION SUCCESFULL");
        } 
        catch (SQLException e) {
            e.printStackTrace();
        }
    }
    
    // Clear out any resources such as open connections.
    // This method will be called at the end of the program.
    public void close(){
        
    }

    /**
     * Add a new artist to the database.
     * @param artist Artist object containing attributes of the artist
     * @throws SQLException
     */
    
    public void addArtist(Artist artist) throws SQLException {
        try{
            String query = "INSERT INTO artist (a_name, birthplace, age, style) VALUES (?, ?, ?, ?)";
            PreparedStatement statement = conn.prepareStatement(query);
            statement.setString(1, artist.getName());
            statement.setString(2, artist.getBirthplace());
            statement.setInt(3, artist.getAge());
            statement.setString(4, artist.getStyle());
            statement.executeUpdate();
        }
        catch(SQLException e){
            System.out.println("Could not add artist" + e);
        }
    }

    /**
     * 1. Add a new artwork.
     * 2. And create a group if it doesn't exist.
     * 3. Then add an entry to the classify table containing artwork title
     * and the group name.
     * All these 3 steps needs to be done using a stored procedure at the database.
     * From the client program, just invoke this stored procedure.
     * @param artwork   Artwork object with the attributes of the artwork.
     * @param group the name of the group
     * @throws SQLException
     */
    public void addArtwork(Artwork artwork, String group) throws SQLException {
        try{
            String sql = "{ CALL add_artwork(?, ?, ?, ?, ?, ?) }";
            CallableStatement statement = conn.prepareCall(sql);

            statement.setString(1, artwork.getTitle());
            statement.setInt(2, artwork.getYear());
            statement.setString(3, artwork.getType());
            statement.setDouble(4, artwork.getPrice());
            statement.setString(5, artwork.getArtistName());
            statement.setString(6, group);

            statement.execute();

            statement.close(); 
        } 
        catch(SQLException e){
            System.out.println("Could not add artwork" + e);
        }
    }

    /**
     * Add a new customer
     * @param customer customer object with the attributes of the customer
     * @throws SQLException
     */
    public void addCustomer(Customer customer) throws SQLException {
        try{
            String query = "INSERT INTO customer (cust_id, c_name, address, amount) VALUES (?, ?, ?, ?)";
            PreparedStatement statement = conn.prepareStatement(query);
            statement.setString(1, customer.getCustomerId());
            statement.setString(2, customer.getCustomerName());
            statement.setString(3, customer.getAddress());
            statement.setDouble(4, customer.getAmount());
            statement.executeUpdate();
        }
        catch(SQLException e){
            System.out.println("Could not add customer" + e); 
        }
    }

    /**
     * Add a record to the like_group table with the customer id and the group name.
     * A part of this exercise is to write a trigger at the database for the insert operation of the like_group.
     * This trigger will invoke a function which does the following.
     * 1. It queries the classify table for the artworks with the same group name.
     * 2. Then it queries for the artist names of these artworks.
     * 3. Finally it should add records to the like_artist table for those artworks with the same customer id
     * as the one which is passed as an argument to this function. This entry is added only if there is no such
     * entry in the like_artist table which was added previously.
     * @param customerId Customer Id
     * @param likeGroup Group Name
     * @throws SQLException
     */
    public void addLikeGroup(String customerId, String likeGroup) throws SQLException {
        
    }

    /**
     * Get the list of artists which are currently available in the database.
     * @return An array of Artist objects where each object corresponds to a record in the artist table.
     * @throws SQLException
     */
    public Artist[] getArtists() throws SQLException {
        Artist[] artist = null; 
        try{
            PreparedStatement statement = conn.prepareStatement("SELECT * FROM artist");
            ResultSet rs = statement.executeQuery();
            ArrayList<Artist> artistList = new ArrayList<>();
            while(rs.next()){
                String name = rs.getString("a_name");
                String birthPlace = rs.getString("birthplace");
                int age = rs.getInt("age");
                String style = rs.getString("style");
                artistList.add(new Artist(name, birthPlace, age, style));
            }
            artist = artistList.toArray(new Artist[artistList.size()]);
        }
        catch(SQLException e){
            System.out.println("Could not add artist" + e); 
        }
        return artist;
    }

    /**
     * Get the list of artworks available in the database.
     * @return An array of Artwork objects where each object corresponds to a record in the artwork table.
     * @throws SQLException
     */
    public Artwork[] getArtworks() throws SQLException {
        Artwork[] artwork = null; 
        try{
            PreparedStatement statement = conn.prepareStatement("SELECT * FROM artwork");
            ResultSet rs = statement.executeQuery();
            ArrayList<Artwork> artworkList = new ArrayList<>();
            while(rs.next()){
                String title = rs.getString("title");
                int year = rs.getInt("year");
                String type = rs.getString("type");
                Float price = rs.getFloat("price");
                String artistName = rs.getString("a_name");
                artworkList.add(new Artwork(title, year, type, price, artistName));
            }
            artwork = artworkList.toArray(new Artwork[artworkList.size()]);
        }
        catch(SQLException e){
            System.out.println("Could not add artist" + e); 
        }
        return artwork;
    }

    /**
     * Get the list of groups.
     * @return An array of Group objects, each object corresponds to a record in the a_groups table.
     * @throws SQLException
     */
    public Group[] getGroups() throws SQLException {
        Group[] groups = null; 
        try{
            PreparedStatement statement = conn.prepareStatement("SELECT * FROM group");
            ResultSet rs = statement.executeQuery();
            ArrayList<Group> groupList = new ArrayList<>();
            while(rs.next()){
                String group = rs.getString("g_name");
                groupList.add(new Group(group));
            }
            groups = groupList.toArray(new Group[groupList.size()]);
        }
        catch(SQLException e){
            System.out.println("Could not add artist" + e); 
        }
        return groups;
    }

    /**
     * Returns List of entries in the classify table.
     * @return an array of classify objects with each objects correspond to a record in the classify table.
     * @throws SQLException
     */
    public Classify[] getClassifyEntries() throws SQLException {
        Classify[] classify = null; 
        try{
            PreparedStatement statement = conn.prepareStatement("SELECT * FROM classify");
            ResultSet rs = statement.executeQuery();
            ArrayList<Classify> classifyList = new ArrayList<>();
            while(rs.next()){
                String title = rs. getString("title");
                String group = rs.getString("g_name");
                classifyList.add(new Classify(title, group));
            }
            classify = classifyList.toArray(new Classify[classifyList.size()]);
        }
        catch(SQLException e){
            System.out.println("Could not add artist" + e); 
        }
        return classify;
    }

    /**
     * Returns the list of like_group table records.
     * @return Array of LikeGroup objects. An object in the array represents on record in the like_group table.
     * @throws SQLException
     */
    public LikeGroup[] getLikeGroupEntries() throws SQLException{
        LikeGroup[] likeGroups = null; 
        try{
            PreparedStatement statement = conn.prepareStatement("SELECT * FROM likeGroups");
            ResultSet rs = statement.executeQuery();
            ArrayList<LikeGroup> likeGroupsList = new ArrayList<>();
            while(rs.next()){
                String customerID = rs. getString("cust_id");
                String groupName = rs.getString("g_name");
                likeGroupsList.add(new LikeGroup(customerID, groupName));
            }
            likeGroups = likeGroupsList.toArray(new LikeGroup[likeGroupsList.size()]);
        }
        catch(SQLException e){
            System.out.println("Could not add artist" + e); 
        }
        return likeGroups;
    }

    /**
     * Returns a list of like_artist records.
     * @return An array of LikeArtist objects. Each object represents one record in like_artist table.
     * @throws SQLException
     */
    public LikeArtist[] getLikeArtistEntries() throws SQLException{
        LikeArtist[] likeArtists = null; 
        try{
            PreparedStatement statement = conn.prepareStatement("SELECT * FROM likeArtists");
            ResultSet rs = statement.executeQuery();
            ArrayList<LikeArtist> likeArtistsList = new ArrayList<>();
            while(rs.next()){
                String customerID = rs. getString("cust_id");
                String artistName = rs.getString("a_name");
                likeArtistsList.add(new LikeArtist(customerID, artistName));
            }
            likeArtists = likeArtistsList.toArray(new LikeArtist[likeArtistsList.size()]);
        }
        catch(SQLException e){
            System.out.println("Could not add artist" + e); 
        }
        return likeArtists;
    }

    /**
     * Updates the 'style' field of an artist record with the given artist name.
     * @param artistName artist name
     * @param newStyle new value of the style field.
     * @throws SQLException
     */
    public void updateArtistStyle(String artistName, String newStyle) throws SQLException {
        try{
            PreparedStatement statement = conn.prepareStatement("UPDATE artist SET style = ? WHERE a_name = ?");
            statement.setString(1, artistName);
            statement.setString(2, newStyle);
            statement.executeUpdate();
        }
        catch(SQLException e){
            System.out.println("Could not update artist style" + e);
        }
    }

}
